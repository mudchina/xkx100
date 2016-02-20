// Room: /d/xingxiu/jiayuguan.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "嘉峪关");
	set("long", @LONG
这是长城最西的关隘。岁月沧桑，仍掩不住它的风采。群山环抱之
下，更显它的雄浑。由于西域安定，久无战事，边关守军已大为减少。
一条大道向东延伸通向中原，万里长城由此往东北方蜿蜒而去。出关向
西，便是著名的“丝绸之路”。
LONG );
	set("outdoors", "silu");
	set("exits", ([
		"eastup"    : __DIR__"xxroad3",
		"west"      : __DIR__"silk1",
		"southup"   : "/d/qilian/tanglangling",
		"northeast" : "/d/qilian/yumen",
		"northwest" : "/d/qilian/danshan",
		"southwest" : "/d/qilian/shalu1",
		"up"	: "/d/changcheng/jiayuguan",
	]));
	set("objects", ([
		__DIR__"npc/wujiang1" : 1,
		__DIR__"npc/bing1" : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -18000);
	set("coor/y", 3000);
	set("coor/z", 0);
	setup();
}
#include "/d/xingxiu/job2.h";
