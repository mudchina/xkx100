// Room: /d/yueyang/yueyanglou1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "岳阳楼");
	set("long", @LONG
岳阳楼始建于唐，背靠岳阳城，俯瞰洞庭湖，遥对君山岛，北依长
江，南极湘江，登楼远眺，一碧无垠，白帆点点，云影波光，气象万千。
全楼高五丈，顶起飞檐，楼顶的形状酷似一顶将军头盔，俗称盔项。
    北宋巴陵郡守滕子京重修岳阳楼，凭栏远眺，诗兴大发：“湖水边
天，天边水，秋来分澄清。君是小蓬瀛，气蒸云梦泽，波撼岳阳城。帝
子有灵能鼓瑟，凄然依旧伤情。微闻兰芷动芳馨，曲终人不见，江上数
峰青。”范仲淹应滕子京之请，为《岳阳楼记》共三百六十字，楼始“
先天下之忧而忧，后天下之乐而乐”而名传。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"up"        : __DIR__"yueyanglou2",
		"south"     : __DIR__"xianmeiting",
		"north"     : __DIR__"sanzuiting",
		"eastdown"  : __DIR__"huaiputing",
		"northeast" : __DIR__"xiaoqiaomu",
	]));
	set("coor/x", -1450);
	set("coor/y", -2260);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
