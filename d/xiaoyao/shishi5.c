// shishi5.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "地下石室");
	set("long", @LONG
这里是地下石室的最下面一层了，四周是黑乎乎，说不出的阴深恐
怖，你可以闻到强烈的腐烂的东西所发出的气味。看来还是快点离开比
较好。
LONG );
	set("exits", ([
		"up" : __DIR__"shishi4",
	]));
	set("objects",([
//		CLASS_D("xiaoyao")+"/xiaoyaozi" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", -21030);
	set("coor/z", -60);
	setup();
	replace_program(ROOM);
}
