// Room: /d/tiezhang/pingtai.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
string look_ditu();
void create()
{
	set("short", BLU"山间平台"NOR);
	set("long", @LONG
这里是山间的一块平地。山势在这里开始分支，矗立在面前的有五
座高耸入云的山峰，行似人的五指，“铁掌山”之名由此而得。五峰虽
同处此山，但拇指峰之雄伟，食指峰之险峻，中指峰之高耸，无名峰之奇
丽，小指峰之秀美，则各有特色，各擅胜场。在平台一侧的大石上，刻着
一副地图(ditu)。
LONG	);
	set("item_desc", ([ 
		"ditu" : (: look_ditu :),
	]));
	set("exits", ([ 
		"westup"    : __DIR__"shanlu5",
		"northeast" : __DIR__"shangu1",
		"eastup"    : __DIR__"sslu1",
		"southdown" : __DIR__"shanlu4",
		"northwest" : __DIR__"hclu1",
		"northup"   : __DIR__"shanlu6",
	]));
	set("objects", ([ 
		__DIR__"npc/huiyi" : 3,
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", -1910);
	set("coor/z", 50);
	setup();
}

string look_ditu()
{
	return
	"\n"
	"############################\n"
	"#          中指峰          #\n"
	"#            ||            #\n"
	"#    无名峰  ||  食指峰    #\n"
	"#         \\ || //         #\n"
	"#          \\||//          #\n"
	"# 小指峰====平台====拇指峰 #\n"
	"############################\n";
	"\n";
}
