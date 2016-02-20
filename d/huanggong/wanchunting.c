// wanchunting.c

inherit ROOM;

void create()
{
	set("short", "万春亭");
	set("long", @LONG
万春亭, 始建于嘉靖十二年. 亭上圆下方, 抱厦四出, 上层伞状圆
顶与下层众多进出的檐角, 组织得极其巧妙. 
LONG
);
	set("outdoors", "huanggong");
	set("exits", ([
		"northwest" : __DIR__"yuhuayuan",
	]) );
	set("objects", ([
		__DIR__"npc/gongnv" : 1,
	]) );
	set("coor/x", -190);
	set("coor/y", 5320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}