#include "Configure.hpp"

void buildSpecification()
{
    DSC<CppSourceTarget> &math = GetCppStaticDSC("math");
    math.getSourceTarget()
        .MODULE_DIRECTORIES_RG("module", ".*")
        //.PRIVATE_COMPILE_DEFINITION("BOOST_MATH_STANDALONE")
        .PRIVATE_INCLUDES("include");

    auto defineTestExe = [&](const string &str) {
        DSC<CppSourceTarget> &test = GetCppExeDSC(str).PRIVATE_LIBRARIES(&math);
        test.getSourceTarget().MODULE_FILES("test/modules/test_" + str + ".cpp");
    };

    defineTestExe("constants");
    defineTestExe("core");
    defineTestExe("policy");
    defineTestExe("sf");
}

MAIN_FUNCTION