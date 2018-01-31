default: build

compile-go:
	go build -buildmode=c-shared -o markdown.so src/golang/markdown.go

build: compile-go
	npm run build