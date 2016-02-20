//Edited by fandog, 01/31/2000

inherit ROOM;
void create ()
{

	set ("short", "牢房");
	set ("long", @LONG
这是约莫两丈见方的一间大石屋，墙壁都是一块块粗糙的大石所砌，
地下也是大石块铺成，墙角落里放着一只粪桶，鼻中闻到的尽是臭气和
霉气。牢房外却可听见燕语呢喃，向燕语处望去，只见一对燕子渐飞渐
远，从数十丈外高楼畔的窗下掠过。那纱窗紧紧地关着，窗槛上却总是
供着一盆鲜花，春天是茉莉、玫瑰，夏天是丁香、凤仙。
LONG);
	set("exits", ([ 
		"west" : __DIR__"yongdao",
	]));
	set("objects", ([
		__DIR__"npc/ding" : 1,
	]));

	set("no_clean_up", 0);
	set("coor/x", -1450);
	set("coor/y", -2029);
	set("coor/z", 0);
	set("no_fight",1);
	setup();
	replace_program(ROOM);
}
