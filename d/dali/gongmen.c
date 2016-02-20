//Room: /d/dali/road1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short", "宫门");
	set("long",@LONG
这里是大理皇宫的宫门，门口放着两个高大石狮，大理皇帝没有
一点架子，从来不禁止人们进入皇宫，往南是御街，往北就进入皇宫
了。
LONG);
	set("outdoors", "daligong");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"qiandian",
	    "south"  : __DIR__"yujie",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40010);
	set("coor/y", -70990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}