// Room: /d/lingxiao/wallw1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "城头");
	set("long", @LONG
狂风吹雪，卷起千堆银屑。孤鸿翔空，拂乱万里云空。“平地不见
雪，白沙入黄云”，正是这种情况的真实写照。远处依稀可见一两个在
当地被称为‘海子’的湖泊，在狂风、白雪、烈日的映照下，挂起点点
鱼鳞之浪。
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"west"     : __DIR__"wallw2",
		"eastdown" : __DIR__"gate",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -31010);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}

