// /guanwai/tianhuo.c

inherit ROOM;

void create()
{
	set("short", "天豁峰");
	set("long", @LONG
乘槎河东岸，与龙门峰对峙。峰顶如鹰嘴般的峻峭山峰破石而出，
伸向天池，故又名鹰嘴峰。古书载：“峰起双尖，中辟一线，有豁然开
朗、令人不可思议之趣”，相传为大禹治水所劈，石多赤色，犹如二龙
蟠踞，妙趣横生。
LONG );
	set("exits", ([
		"south" : __DIR__"huagai",
		"west"  : __DIR__"longmen",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6200);
	set("coor/y", 5180);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}