# image_visual_db
demo_project
The image_visual_db demo project is a key value store database written in C++.
The program creates an ImageDB object where the user will enter their datapath to their image ,and the name of the picture along with the time the put operation was called.
Each input will be done through a put() operation that will make send the binaries to a buffer object which stores each entry in a vector.
Each buffer object will contain the an em_visual_db object that will contain the bytes of each image, image path, name of image, and time entry was called.
The buffer will reach its max capcity and send the oldest generated image to a storage system call EM_storage which will use a hashtable to store the time of entry made as the key and the binary will be the value.
