from os.path import join

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
from conan.tools.files import copy


class SemanticRoleLabelingConan(ConanFile):
    name = "semantic_role_labeling"
    version = "1.0.0"
    requires = ["annotated_tree/1.0.0",
                "n_gram/1.0.0",
                "morphological_analysis/1.0.0",
                "dictionary/1.0.0",
                "corpus/1.0.0",
                "annotated_sentence/1.0.0",
                "named_entity_recognition/1.0.0",
                "prop_bank/1.0.0",
                "frame_net/1.0.0",
                "dependency_parser/1.0.0",
                "senti_net/1.0.0",
                "xml_parser/1.0.0",
                "word_net/1.0.0",
                "parse_tree/1.0.0"]
    license = "GPL License"
    author = "Olcay Taner Yildiz olcay.yildiz@ozyegin.edu.tr"
    url = "https://github.com/StarlangSoftware/SemanticRoleLabeling-CPP"
    description = "Semantic Role Labeling Interface and Automatic Annotation Algorithms"
    topics = ("")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    exports_sources = "src/*", "Test/*"

    def layout(self):
        cmake_layout(self, src_folder="src")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        copy(conanfile=self, keep_path=True, src=join(self.source_folder), dst=join(self.package_folder, "include"), pattern="*.h")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.a")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.so")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.dylib")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "bin"), pattern="*.dll")

    def package_info(self):
        self.cpp_info.libs = ["SemanticRoleLabeling"]
