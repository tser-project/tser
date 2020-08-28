.PHONY: build

ANTLR=java -jar /usr/local/lib/antlr-4.8-complete.jar
GRUN=java org.antlr.v4.gui.TestRig

OUTPUT_NAME=tser
DIST_PATH=./dist

### for tser ###

# build tser package
build:
	make build-main;
	make build-builtin;
	make build-package;

# build tser package for debug
build-debug:
	make build-main-debug;
	make build-builtin;
	make build-package;

# build main executable binary file 
build-main: clean-main-build
	mkdir -p build && pushd build; \
	cmake ..; \
	make -j8; \
	popd;

# build main executable binary file for debug
build-main-debug: clean-main-build
	mkdir -p build && pushd build; \
	cmake .. -DCMAKE_BUILD_TYPE=Debug; \
	make -j8; \
	popd;

# clean tser build
clean-main-build:
	rm -rf ./build/*

### for tser's builtin ###

# build builtin functions, linking while running
build-builtin: clean-builtin
	mkdir -p src/builtin/build && pushd src/builtin/build; \
	cmake ..; \
	MACOSX_DEPLOYMENT_TARGET=10.13.6 make; \
	ld -r CMakeFiles/builtin.dir/*.cpp.o -o builtin.o;

# clean build of builtin
clean-builtin:
	rm -rf ./src/builtin/build/*;

### for parser ###

# build TypeScript parser
build-parser: 
	rm -rf ./src/grammar/build/* && mkdir -p ./src/grammar/build && pushd src/grammar/build; \
	cmake ..; \
	make -j8; \
	popd;

# run AST's GUI review
parser-grun:
	pushd .grun; \
	$(GRUN) TypeScript program -gui;

# generate parser c++ code
generate-parser: clean-parser
	pushd src/grammar; \
	$(ANTLR) -Dlanguage=Cpp TypeScriptLexer.g4 -visitor; \
	$(ANTLR) -Dlanguage=Cpp TypeScriptParser.g4 -visitor; \
	popd;
	make generate-parser-grun;

# generate grun code, for AST's GUI review (use java, antlr grun doesn't support c++)
generate-parser-grun:
	mkdir -p .grun && rm -rf .grun/*;
	cp src/grammar/TypeScriptLexer.g4 .grun/TypeScriptLexer.g4;
	cp src/grammar/TypeScriptParser.g4 .grun/TypeScriptParser.g4;
	mkdir -p .grun && pushd .grun; \
	$(ANTLR) TypeScriptLexer.g4 TypeScriptParser.g4 -visitor; \
	javac TypeScript*.java; \
	popd;

# clean parser c++ code and built output
clean-parser:
	rm -rf ./src/grammar/*.cpp
	rm -rf ./src/grammar/*.h
	rm -rf ./src/grammar/*.interp
	rm -rf ./src/grammar/*.tokens

# build release package
build-package:
	rm -rf $(DIST_PATH)/*;
	mkdir -p $(DIST_PATH)/bin $(DIST_PATH)/lib;
	cp ./src/builtin/build/builtin.o $(DIST_PATH)/lib;
	cp ./build/tser $(DIST_PATH)/bin;
	cp {./LICENSE,README.md} $(DIST_PATH);