// Room: /d/lingxiao/dadian.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
string look_duilian();
#include <ansi.h>
void create()
{
	set("short", "凌霄殿");
	set("long", 
"这里就是凌霄城的根本之地──凌霄殿。向来，不管凌霄城有何大
事，掌门都会在此召集门人，发号施令。大厅北墙上，挂着一个老人的
肖像，是当年凌霄城创派祖师的遗像。两边柱子上刻着一幅对联(lian)。
旁边的兵器架上放满了寒光闪闪的长剑。堂额挂着一张匾，上书四个大
字。"HIB"

                       梅雪凌霄
\n"NOR);
        set("valid_startroom", 1);
	set("item_desc",([
		"lian" : (: look_duilian :),
	]));
	set("exits", ([
		"east"  : __DIR__"fudian2",
		"west"  : __DIR__"fudian1",
		"north" : __DIR__"qianyuan",
		"out"   : __DIR__"meiroad1",
	]));
	set("objects", ([
		__DIR__"npc/lu" : 1,
		__DIR__"npc/dizi" : 3,
	]));
	set("coor/x", -31000);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	"/clone/board/lingxiao_b"->foo();
} 

string look_duilian()
{
	return
	"\n"
	"    ※※※※※※※※※※※※※※※※※\n"
	"    ※※※※　　　　　　　　  ※※※※\n"
	"    ※※※※　宝          梅　※※※※\n"
	"    ※※※※　剑          花　※※※※\n"
	"    ※※※※　锋          香　※※※※\n"
	"    ※※※※　自          自　※※※※\n"
	"    ※※※※　磨          苦　※※※※\n"
	"    ※※※※　砺          寒　※※※※\n"
	"    ※※※※　出          来　※※※※\n"
	"    ※※※※　　　　　　　　　※※※※\n"
	"    ※※※※※※※※※※※※※※※※※\n\n";
}

