// ROOM lianfushi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "斧头林");
	set("long", @LONG
这里是玄兵古洞的打造斧头的地方。处在密密层层的丛林中。林中
有一块小小空地，摆着一个很简陋的铁炉和风箱，旁边一个虬须大汉手
拉风箱，双目全神贯注盯着炉中兰色的火苗。
LONG );
	set("exits", ([
		"south" : "/d/heizhao/shanlu3",
	]));
	set("objects", ([
		__DIR__"npc/shifu" :1,
	]));
	set("coor/x", -4000);
	set("coor/y", -1490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
