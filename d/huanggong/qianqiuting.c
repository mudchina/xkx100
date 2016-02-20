// qianqiuting.c

inherit ROOM;

void create()
{
	set("short", "千秋亭");
	set("long", @LONG
前明嘉靖十二年构建修建的千秋亭上圆下方, 抱厦四出, 上层伞状
圆顶与下层众多进出的檐角, 组织得极其巧妙.
LONG
);
	set("outdoors", "huanggong");
	set("exits", ([
		"northeast" : __DIR__"yuhuayuan",
	]) );
	set("objects", ([
		__DIR__"npc/gongnv" : 1,
	]) );
	set("coor/x", -210);
	set("coor/y", 5320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}