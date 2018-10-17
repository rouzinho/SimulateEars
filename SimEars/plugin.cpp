#include "plugin.h"
#include "SimEar.h"
#include <cedar/processing/ElementDeclaration.h>

void pluginDeclaration(cedar::aux::PluginDeclarationListPtr plugin)
{
    cedar::proc::ElementDeclarationPtr summation_decl
    (
        new cedar::proc::ElementDeclarationTemplate <SimEar>("Utilities")
    );
    plugin->add(summation_decl);
}
