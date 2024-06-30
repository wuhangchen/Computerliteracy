 void send( int * to, int * from, int count)
          //    Duff设施，有帮助的注释被有意删去了  
 {
          int n = (count + 7 ) / 8 ;
          switch (count % 8 ) {
          case 0 :    do { * to ++ = * from ++ ;
          case 7 :          * to ++ = * from ++ ;
          case 6 :          * to ++ = * from ++ ;
          case 5 :          * to ++ = * from ++ ;
          case 4 :          * to ++ = * from ++ ;
          case 3 :          * to ++ = * from ++ ;
          case 2 :          * to ++ = * from ++ ;
          case 1 :          * to ++ = * from ++ ;
                 } while ( -- n >    0 );
         }  
 }
//整个代码并不是毫无道理的，无论是gcc还是在vc环境下都可以完美的编译通过，
//根据switch语句悬着对应的case的语句，然后进入do while语句，进行循环。 
 static void(*set_malloc_hander(void(*f)()));
 //接受一个函数指针，返回一个一个函数指针。
 using tmp = void (*f)();
 static void (*set_malloc_hander(tmp));
 
 
 //C++14
 template<typename T,typename U>
 inline auto max(T a,U b)
 {
	 return a>b?a:b;
 }