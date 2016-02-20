// Room: /yangzhou/chuitai.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "吹台");
	set("long", @LONG
吹台俗称钓鱼台，在绿荫馆西伸向湖心长渚尽头。亭台三面临湖，
与五亭桥、白塔隔湖相望，相传乾隆皇帝曾在此垂钓。亭为四方，重檐
斗角黄墙，板瓦顶，面东装木刻缕空落地罩阁门，下置短栏。濒湖三面
各开圆洞门。面吹台偏北而立，视西侧圆门，景收五亭桥；看南侧洞门，
映白塔高耸。以门借景，昔有"三星拱照"之称。内悬“吹台”匾，外则
悬“钓鱼台”匾。敞门两侧悬挂楹联(lian)。
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIC"
        浩        把
        歌        钓
        向        待
        兰        秋
        渚        风
\n"NOR
	]));
	set("exits", ([
		"east"  : __DIR__"pingtai2",
		"south" : __DIR__"balongqiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}