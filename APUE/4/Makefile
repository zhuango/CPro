obj1=readlink 
obj2=remove
obj3=rename    
obj4=symlink   
obj5=truncate 
obj6=access    
obj7=chmod_f 
obj8=umask    
obj9=unlk    
obj10=utime
CC:=gcc
$(obj1):$(obj1).o
	$(CC)	$(obj1):.o -o $(obj1)
$(obj1).o:$(obj1).c
	CC	-c $(obj1):.c -o $(obj1):.o

$(obj2):$(obj2).o
	CC  $(obj2).o -o $(obj2)
$(obj2).o:$(obj2).c
	CC  -c $(obj2).c -o $(obj2).o

$(obj3):$(obj3).o
	CC  $(obj3).o -o $(obj3)
$(obj3).o:$(obj3).c
	CC  -c $(obj3).c -o $(obj3).o

$(obj4):$(obj4).o
	CC  $(obj4).o -o $(obj4)
$(obj4).o:$(obj4).c
	CC  -c $(obj4).c -o $(obj4).o

$(obj5):$(obj5).o
	CC  $(obj5).o -o $(obj5)
$(obj5).o:$(obj5).c
	CC  -c $(obj5).c -o $(obj5).o

$(obj6):$(obj6).o
	CC  $(obj6).o -o $(obj6)
$(obj1).o:$(obj6).c
	CC  -c $(obj6).c -o $(obj6).o

$(obj7):$(obj7).o
	CC  $(obj7).o -o $(obj7)
$(obj7).o:$(obj7).c
	CC  -c $(obj7).c -o $(obj7).o

$(obj8):$(obj8).o        
	CC  $(obj8).o -o $(obj8)
$(obj8).o:$(obj8).c
	CC  -c $(obj8).c -o $(obj8).o

$(obj9):$(obj9).o        
	CC  $(obj9).o -o $(obj9)
$(obj9).o:$(obj9).c
	CC  -c $(obj9).c -o $(obj9).o

$(obj10):$(obj10).o        
	CC  $(obj10).o -o $(obj10)
$(obj10).o:$(obj10).c
	CC  -c $(obj10).c -o $(obj10).o


.PHONY:clean
clean:
	rm $(obj1) $(obj2) $(obj3) $(obj4) $(obj5) $(obj6) $(obj7) $(obj8) $(obj9) $(obj10) *.o
