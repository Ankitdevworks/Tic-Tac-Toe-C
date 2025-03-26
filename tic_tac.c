#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char a , b , c , d , e , f, g , h , i ;
void board() ;
void play() ;
char *check(int) ;
void result() ;
void out(char) ;
char cond() ;
bool emp() ;
void ident( int k) ;
int main(){
    a = '1' ;
    b = '2' ;
    c = '3' ;
    d = '4' ;
    e = '5' ;
    f = '6' ;
    g = '7' ;
    h = '8' ;
    i = '9' ;
    board() ;
    play() ;
    return 0 ;
}
void board(){
    printf("%2c |",a) ;
    printf("%2c |",b) ;
    printf("%2c\n",c)  ;
    printf("------------\n") ;
    printf("%2c |",d) ;
    printf("%2c |",e) ;
    printf("%2c\n",f)  ;
    printf("------------\n") ;
    printf("%2c |",g) ;
    printf("%2c |",h) ;
    printf("%2c\n",i) ;
}
void play(){
    static int index = 0 , turn ;
if(index % 2 == 0 ){
     printf("its 'X' turn ") ;
     scanf("%d",&turn) ;
     ident(turn) ;
     index = index + 1 ;
     *(check(turn)) = 'X' ;
     board() ;
     result() ;
    }
else{
      printf("its 'Y' turn ") ;
      scanf("%d",&turn) ;
      ident(turn) ;
     index = index + 1 ;
      *(check(turn)) = 'Y' ;
      board() ;
      result() ;
    }
}
char *check(int l){
    switch(l){
        case  1 :
        return &a ;
        break ;
        case  2 :
        return &b ;
        break ;
        case  3 :
        return &c ;
        break ;
        case  4 :
        return &d ;
        break ;
        case  5 :
        return &e ;
        break ;
        case  6 :
        return &f ;
        break ;
        case  7 :
        return &g ;
        break ;
        case  8 :
        return &h ;
        break ;
        case  9 :
        return &i ;
        break ;
        default :
        printf("please enter valid input b/w (1-9) \n") ;
        play() ;
        exit(0) ;
    }
}
void result(){
    cond() ? out(cond()) : play() ; 
}
char cond(){
    if( a == b && b == c){
        return a ;
    }
    else if( a == d && a == g ){
        return a ;
    }
    else if( a == e && a == i ){
        return a ;
    }
    else if( e == d && e == f ){
        return e ;
    }
    else if( h == i && h == g ){
        return h ;
    }
    else if( c == e && c == g ){
        return c ;
    }
    else if( c == f && c == i ){
        return c ;
    }
    else if( b == e && b == h ){
        return b ;
    }
    else if( emp() ){
        return '\0' ;
    }
    else{
        printf("Match Draw!!...") ;
        exit(0) ;
    }
}
void out(char m ){
printf("'%c' Won !!....",m) ;
}
bool emp(){
    if(a != '1' && b != '2' && c != '3' &&
        d != '4' && e != '5' && f != '6' &&
        g != '7' && h != '8' && i != '9'){
        return false ;
    }
    return true ;
}
void ident( int k){
    if(*(check(k)) == 'X' || *(check(k)) == 'Y' ){
        printf("you can not update moves \n choose empty blocks\n") ;
        play() ;
    }
    return
;}