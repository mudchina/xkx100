// /d/xiakedao/duchuan.c
#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "小舟");
        set("long",@LONG
这是一只几尺见方的小舟，除了船尾划桨的黄衣侠客岛接送弟
子外，再不能坐第三个人了。海面几乎和船帮平齐。还好没什么风
浪，你正暗自庆幸。
LONG);   
        set("outdoors", "xiakedao");
        set("no_clean_up", 0);
        set("coor/x", -3000);
	set("coor/y", -10000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM) ;
}
