//ROOM: /d/yanziwu/dannuo.c

inherit ROOM;
void create()
{
	set("short", "啖糯厅");
	set("long",@LONG
这是一间雅致的大厅，厅上摆着几张紫檀木大桌。桌上银制餐具一
应俱全，桌边一溜犁花木椅。每日慕容世家很多人都在此用餐。
LONG );
	set("exits", ([
		"west" : __DIR__"yimen",
		"east" : __DIR__"huayuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 830);
	set("coor/y", -1530);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}