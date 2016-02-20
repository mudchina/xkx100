// ROOM lianqiang.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "作枪洞");
	set("long", @LONG
这里是玄兵古洞的造枪的地方。地处铁掌峰潮阴之处，四周洞壁黑
幽幽的，中间放着一个巨大的炉子，冒着蓬蓬的蓝炎，倒把整个洞照得
挺光亮的。
LONG );
	set("exits", ([
		"west" : "/d/tiezhang/sslin2",
	]));
	set("objects",([
		__DIR__"npc/shiqiang" :1,
	]));
	set("coor/x", -2020);
	set("coor/y", -1880);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
