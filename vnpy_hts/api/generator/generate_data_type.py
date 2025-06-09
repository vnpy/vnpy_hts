""""""

TYPE_CPP2PY = {
    "int": "int",
    "char": "char",
    "double": "double",
    "short": "int",
    "long": "int",
    "ax_int8": "int",
    "ax_int16": "int",
    "ax_int32": "int",
    "ax_int64": "int",
    "ax_uint8": "int",
    "ax_uint16": "int",
    "ax_uint32": "int",
    "ax_uint64": "int",
    "ax_size8": "int",
    "ax_size16": "int",
    "ax_size32": "int",
    "ax_size64": "int",
    "ax_vbool": "int",
    "ax_vbyte": "char",
    "ax_vdate": "int",
    "ax_float32": "float",
    "ax_float64": "double",
}


class DataTypeGenerator:
    """DataType生成器"""

    def __init__(self, filename: str, prefix: str):
        """Constructor"""
        self.filename = filename
        self.prefix = prefix

    def run(self):
        """主函数"""
        self.f_cpp = open(self.filename, encoding="UTF-8")
        self.f_define = open(f"{self.prefix}_constant.py", "w")
        self.f_typedef = open(f"{self.prefix}_typedef.py", "w")

        for line in self.f_cpp:
            self.process_line(line)

        self.f_cpp.close()
        self.f_define.close()
        self.f_typedef.close()

        print("DataType生成完毕")

    def process_line(self, line: str):
        """处理每行"""
        line = line.replace("\n", "")
        line = line.replace(";", "")

        if line.startswith("#define"):
            self.process_define(line)
        elif line.startswith("typedef"):
            self.process_typedef(line)

    def process_define(self, line: str):
        """处理常量定义"""
        words = line.split(" ")
        words = [word for word in words if word]
        if len(words) < 3:
            return

        name = words[1]
        value = words[2]

        new_line = f"{name} = {value}\n"
        self.f_define.write(new_line)

    def process_typedef(self, line: str):
        """处理类型定义"""
        words = line.split(" ")
        words = [word for word in words if word != ""]

        name = words[2]
        typedef = TYPE_CPP2PY[words[1]]

        if typedef == "char":
            if "[" in name:
                typedef = "string"
                name = name[:name.index("[")]

        new_line = f"{name} = \"{typedef}\"\n"
        self.f_typedef.write(new_line)


if __name__ == "__main__":
    generator = DataTypeGenerator("../include/hts/DFITCSECApiDataType.h", "HTS")
    generator.run()
