//Room /d/yanziwu/chufang.c
inherit ROOM;
void create()
{
	set("short","厨房");
	set("long",@LONG
这是间宽敞的厨房，厨师们在展示各自的烹饪绝活。整个房间弥漫
着令人垂涎欲滴的菜香。
LONG );
	set("exits",([
		"north" : __DIR__"xiaoting",
	]));
	set("objects",([
		__DIR__"npc/nanpu" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 820);
	set("coor/y", -1510);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}