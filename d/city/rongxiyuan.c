// Room: /yangzhou/rongxiyuan.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "容膝园");
	set("long", @LONG
在园之东北隅，叠山石一撮，植花木少许。在园之西侧，贴墙筑半
廊，与半亭连续。于园之西南，横断园林，造客斋一间。斋之南，留有
隙地，到也小有天地。整个园地，纵深约三十步，宽仅十步许。身步不
移，全园景物，即可全收眼底。北向有堂屋一间。
LONG );

	set("outdoors", "yangzhouw");
	set("exits", ([
		"south" : __DIR__"hejiajie",
		"north" : __DIR__"tangwu1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}