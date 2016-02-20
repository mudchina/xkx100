// Room: /wuliang/zhengting.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "练武厅");
	set("long", @LONG
练武厅东坐着二人。上首是个四十左右的中年道姑，铁青着脸，
嘴唇紧闭。下首是个五十余岁的老者，右手捻着长须，神情甚是得意。
两人的座位相距一丈有余，身后各站着二十余名男女弟子。
LONG );
	set("exits", ([
		"southdown"  : __DIR__"road1",
		"east"       : __DIR__"road2",
		"west"       : __DIR__"road3",
		"north"      : __DIR__"road4",
	]));
	set("objects", ([
		__DIR__"npc/zuo"  : 1,
		__DIR__"npc/xin"  : 1,
		__DIR__"npc/gong" : 1,
		__DIR__"npc/qi" : 1,
	]));
	set("coor/x", -71000);
	set("coor/y", -79890);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}