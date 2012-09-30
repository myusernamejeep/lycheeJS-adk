
#ifndef LIB_FS_H_
#define LIB_FS_H_

#include <v8.h>


namespace lib {

	class FS {

		private:

		public:

			static v8::Handle<v8::ObjectTemplate> generate(void);

			static v8::Handle<v8::Value> handleRead(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleWrite(const v8::Arguments& args);

			static char* read(char* path);
			static char* readVM(char* path);
			static bool write(char* path, char* data, size_t length);
			static bool writeVM(char* path, char* data, size_t length);

			static char* getReal(char* path);
			static void setVMRoot(char* program_path, char* file_path);
			static char *pushVMRoot(char *new_path);
			static void popVMRoot(char *old_path);
			static char* getVMRoot(void);


	};

};

#endif
 
