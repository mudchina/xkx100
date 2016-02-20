//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "大厅");
	set ("long", @LONG
这是万家为庆祝老爷子五十大寿布置的大厅，前来拜寿的客人已陆
续就座，几个丫鬟仆人正忙着端茶送水，大厅上一个身形魁梧的老者正
在和众宾客周旋。
LONG);
	set("exits", ([
		"west"  : __DIR__"damen",
		"east"  : __DIR__"zoulang1",
		"south" : __DIR__"nanlou",
		"north" : __DIR__"beilou",
	]));
	set("objects", ([
		__DIR__"npc/wanzhenshan" : 1,
		__DIR__"npc/lvtong"      : 1,
		__DIR__"npc/lukun"       : 1,
		__DIR__"npc/zhouqi"      : 1,
	]));

	set("coor/x", -1489);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
