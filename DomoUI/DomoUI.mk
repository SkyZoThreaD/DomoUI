##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=DomoUI
ConfigurationName      :=Debug
WorkspacePath          := "/home/tupac/Documents/DomoUI"
ProjectPath            := "/home/tupac/Documents/DomoUI/DomoUI"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=03/02/16
CodeLitePath           :="/home/tupac/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="DomoUI.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -lGLU -lGL -lX11
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Mesh.cpp$(ObjectSuffix) $(IntermediateDirectory)/Exception.cpp$(ObjectSuffix) $(IntermediateDirectory)/Vector3f.cpp$(ObjectSuffix) $(IntermediateDirectory)/Texture.cpp$(ObjectSuffix) $(IntermediateDirectory)/ResourceMgr.cpp$(ObjectSuffix) $(IntermediateDirectory)/Renderable.cpp$(ObjectSuffix) $(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tupac/Documents/DomoUI/DomoUI/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Mesh.cpp$(ObjectSuffix): Mesh.cpp $(IntermediateDirectory)/Mesh.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tupac/Documents/DomoUI/DomoUI/Mesh.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Mesh.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Mesh.cpp$(DependSuffix): Mesh.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Mesh.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Mesh.cpp$(DependSuffix) -MM "Mesh.cpp"

$(IntermediateDirectory)/Mesh.cpp$(PreprocessSuffix): Mesh.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Mesh.cpp$(PreprocessSuffix) "Mesh.cpp"

$(IntermediateDirectory)/Exception.cpp$(ObjectSuffix): Exception.cpp $(IntermediateDirectory)/Exception.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tupac/Documents/DomoUI/DomoUI/Exception.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Exception.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Exception.cpp$(DependSuffix): Exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Exception.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Exception.cpp$(DependSuffix) -MM "Exception.cpp"

$(IntermediateDirectory)/Exception.cpp$(PreprocessSuffix): Exception.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Exception.cpp$(PreprocessSuffix) "Exception.cpp"

$(IntermediateDirectory)/Vector3f.cpp$(ObjectSuffix): Vector3f.cpp $(IntermediateDirectory)/Vector3f.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tupac/Documents/DomoUI/DomoUI/Vector3f.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Vector3f.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Vector3f.cpp$(DependSuffix): Vector3f.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Vector3f.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Vector3f.cpp$(DependSuffix) -MM "Vector3f.cpp"

$(IntermediateDirectory)/Vector3f.cpp$(PreprocessSuffix): Vector3f.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Vector3f.cpp$(PreprocessSuffix) "Vector3f.cpp"

$(IntermediateDirectory)/Texture.cpp$(ObjectSuffix): Texture.cpp $(IntermediateDirectory)/Texture.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tupac/Documents/DomoUI/DomoUI/Texture.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Texture.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Texture.cpp$(DependSuffix): Texture.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Texture.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Texture.cpp$(DependSuffix) -MM "Texture.cpp"

$(IntermediateDirectory)/Texture.cpp$(PreprocessSuffix): Texture.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Texture.cpp$(PreprocessSuffix) "Texture.cpp"

$(IntermediateDirectory)/ResourceMgr.cpp$(ObjectSuffix): ResourceMgr.cpp $(IntermediateDirectory)/ResourceMgr.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tupac/Documents/DomoUI/DomoUI/ResourceMgr.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ResourceMgr.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ResourceMgr.cpp$(DependSuffix): ResourceMgr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ResourceMgr.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ResourceMgr.cpp$(DependSuffix) -MM "ResourceMgr.cpp"

$(IntermediateDirectory)/ResourceMgr.cpp$(PreprocessSuffix): ResourceMgr.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ResourceMgr.cpp$(PreprocessSuffix) "ResourceMgr.cpp"

$(IntermediateDirectory)/Renderable.cpp$(ObjectSuffix): Renderable.cpp $(IntermediateDirectory)/Renderable.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tupac/Documents/DomoUI/DomoUI/Renderable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Renderable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Renderable.cpp$(DependSuffix): Renderable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Renderable.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Renderable.cpp$(DependSuffix) -MM "Renderable.cpp"

$(IntermediateDirectory)/Renderable.cpp$(PreprocessSuffix): Renderable.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Renderable.cpp$(PreprocessSuffix) "Renderable.cpp"

$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix): Engine.cpp $(IntermediateDirectory)/Engine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tupac/Documents/DomoUI/DomoUI/Engine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Engine.cpp$(DependSuffix): Engine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Engine.cpp$(DependSuffix) -MM "Engine.cpp"

$(IntermediateDirectory)/Engine.cpp$(PreprocessSuffix): Engine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Engine.cpp$(PreprocessSuffix) "Engine.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


