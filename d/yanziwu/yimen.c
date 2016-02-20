//ROOM: /d/yanziwu/yimen.c

inherit ROOM;

void create()
{
	set("short", "仪门");
	set("long",@LONG
一扇朱漆的雕花大门，一块醒目的牌子挂于门上，上镌黑色小篆写
的 "仪门" 二字，给人一种庄严威武的感觉。东面就是燕子坞门人休息
的地方，向西则是慕容家人用饭的啖糯厅。
LONG );
	set("exits", ([
		"west"  : __DIR__"qinfang1",
		"east"  : __DIR__"dannuo",
		"north" : __DIR__"longfeng",
		"south" : __DIR__"canheju",
	]));
	set("no_clean_up", 0);
	set("coor/x", 820);
	set("coor/y", -1530);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}