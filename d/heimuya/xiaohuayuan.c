// Room: /d/heimuya/xiaohuayuan.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "小花园");
	set("long", @LONG
从昏暗的地道中出来，你发现自己竟是置身于一个极精致的小花园
中，红梅绿竹，青松翠柏，布置得颇具匠心，往东去，是一间很精雅的
小舍。
LONG  );
	set("outdoors", "heimuya");
	set("exits", ([
		"south" : __DIR__"didao6",
		"enter" :__DIR__"xiaoshe",   
	]));
	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}