#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","独孤求败埋骨之洞");
	set("long",@LONG
这洞其实甚浅，行不到三丈，已抵尽头。洞中除了一张石桌和一
张石凳外就别无他物了。洞角有一堆乱石高起，极似一个坟墓，岩壁
上刻着三行字道：
    「纵横江湖三十余载，杀尽仇寇，败尽英雄，天下更无抗手，无
可奈何，惟隐居深谷，以雕为友。呜呼，生平求一敌手而不可得，诚
寂寥难堪也。
                                         剑魔独孤求败。」
LONG
	);
	set("exits",([
		"south":__DIR__"shandong1",
	]));
	set("coor/x", -400);
	set("coor/y", -430);
	set("coor/z", 0);
	setup();
}
void init()
{
	object me=this_player();
	me->set_temp("dugu_visit",1);
}	