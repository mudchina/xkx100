//ROOM: /d/yanziwu/muti.c

inherit ROOM;

void create()
{
	set("short", "木梯");
	set("long",@LONG
这是一座松树枝架成的木梯，垂下来通往水面。忽听得旁边柳枝上
一只小鸟 "莎莎都莎，莎莎都莎" 的叫了起来，把你吓了一跳。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"eastup" : __DIR__"qinyun",
	]));
	set("no_clean_up", 0);
	set("coor/x", 800);
	set("coor/y", -1500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}