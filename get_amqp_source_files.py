from os import listdir
from os.path import isfile, join, isdir

def getAllFilesRecursive(root):
    h_files = [ join(root,f) for f in listdir(root) if isfile(join(root,f)) and join(root,f)[-2:] == ".h"]
    c_files = [ join(root,f) for f in listdir(root) if isfile(join(root,f)) and join(root,f)[-2:] == ".c"]

    dirs = [ d for d in listdir(root) if isdir(join(root,d))]
    for d in dirs:
        c_files_in_d, h_files_in_d = getAllFilesRecursive(join(root,d))

        for f in h_files_in_d:
        	h_files.append(f)

        for f in c_files_in_d:
        	c_files.append(f)


    return c_files, h_files


if __name__ == "__main__":
	'''
	Traverse the given directory and prepare cmake list (APPEND ) commands for each file
	'''
	#list_of_files = getAllFilesRecursive("deps/amqp")

	cmake_prefix_c_string = "list(APPEND default_plugin_sources ${PROJECT_SOURCE_DIR}/"
	cmake_prefix_h_string = "list(APPEND default_plugin_headers ${PROJECT_SOURCE_DIR}/"

	list_of_dirs = ["deps/amqp", "plugins/amqp"]

	c_file_list = []
	h_file_list = []

	for d in list_of_dirs:
		c_files, h_files = getAllFilesRecursive(d)
		c_file_list = c_file_list + c_files
		h_file_list = h_file_list + h_files


	with open ("amqp_headers.txt", "w") as f:
		for file in h_file_list:
			file = cmake_prefix_h_string + file + ")\n"
			f.write(file)

	with open("amqp_sources.txt", "w") as f:
		for file in c_file_list:
			file = cmake_prefix_c_string + file + ")\n"
			f.write(file)		

#	for file in list_of_files:
#		file = cmake_prefix_string + file + ")"
#		print(file)

