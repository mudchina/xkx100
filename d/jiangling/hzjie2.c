//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "汉正街");
	set ("long", @LONG
这是武汉最繁华的街道。从大江南北来的各色人等，熙熙攘攘，摩
肩接踵。西边是一家小吃店，门口的招帘上写着“老通城”三个大字。
东边是一个码头。你侧耳细听，可以听到江水拍打江岸的涛声。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"east" : __DIR__"matou1",
		"west" : __DIR__"laotc",
		"south": __DIR__"hzjie3",
		"north": __DIR__"hzjie1",
	]));

	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
