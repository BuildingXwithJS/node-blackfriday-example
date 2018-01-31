package main

import "C"
import "gopkg.in/russross/blackfriday.v2"

//export Markdown
func Markdown(input *C.char) *C.char {
	inputString := C.GoString(input)
	res := blackfriday.Run([]byte(inputString))
	resString := string(res)
	return C.CString(resString)
}

func main() {}
