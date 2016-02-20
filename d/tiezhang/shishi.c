// Room: /d/tiezhang/shishi.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "石室");
	set("long", @LONG
这是一间在山腹中凿成的小石屋，中间有一座石桌，桌上摆放着一
盏油灯，散发出暗淡昏黄的光亮。屋内一角的地上，铺着很多干草，上
面坐着一个人。长发垂下，遮去面容，看不出多大年纪，身上穿着一件
又脏又破的黑衣，说不出的诡异神秘。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"eastup" : __DIR__"shijie3",
	]));
	set("objects", ([
		CLASS_D("tiezhang")+"/shangguan" : 1,
	]));
	set("no_clean_up", 0);

	set("coor/x", -2050);
	set("coor/y", 1870);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
