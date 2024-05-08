# 编译course.c生成course可执行文件  
course: course.c  
	gcc course.c -o course  
  
# run目标依赖于course目标，它会先编译course.c，然后运行course  
run: course  
	./course  
  
# 定义run和clean为伪目标  
.PHONY: run clean  
  
# 默认目标是run  
all: run  
  
# 清除生成的文件  
clean:  
	rm -f course