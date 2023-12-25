# Windows API
## Solution setup

- C/C++\General\Multi Processor Compilation -> Yes
- C/C++\Optimisation\Favor size or speed -> Favor fast code  
**Change Configuration to Release**  
- C/C++\Preprocessor\Preprocessor Definitions -> Add "NDEBUG"  
  `This is important if we wanna link to standart library statically`  
- C/C++\Preprocessor\Code generation\Runtime library -> Multi-threaded (/MT)  
**Change Configuration to Debug**  
- C/C++\Preprocessor\Code generation\Runtime library -> Multi-threaded Debug (/MTd)  
  **Change Configuration to All Configurations**  
- C/C++\Code generation\Floating Point Model -> Fast  
- C/C++\Language\C++ Language standard->Latest
- C/C++\Linker\System\SubSystem -> Windows

## Windows setup

```cpp
int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	  lpCmdLine,
	int		  nCmdShow)
```

