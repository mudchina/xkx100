// Room: /d/quanzhou/lingshan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "灵山圣墓");
	set("long", @LONG
这是泉州东边灵山的南麓，传闻唐高祖武德年间，伊斯兰教创始人
穆罕莫德派门徒三贤沙仕偈、四贤吾高仕来泉州传教，卒葬于此。墓后
有一半圆形石筑廊，上立有一中文碑记，乃「郑和行香碑」(monument)。
这是著名航海家三宝太监郑和第五次下西洋路过泉州，特至此墓行香祷
告，官府为之刻石记事的碑刻。
LONG );
	set("outdoors", "quanzhou");
	set("item_desc", ([
		"monument" :
"【钦差总兵太监郑和，前往西洋忽鲁漠斯等国公干。永乐
十五年来此行香，望神灵保佑。镇抚浦和日记立】\n",
	]));
	set("exits", ([
		"south" : __DIR__"portroad1",
		"west"  : __DIR__"tumenshuiguan",
		"east"  : __DIR__"luoyangqiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1880);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
