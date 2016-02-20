// Room: /d/yanping/xita.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "西塔");
	set("long", @LONG
西塔竣于明万历三十五年六月，矗立于九龙岩顶，高七丈，七层八
角，实心青石构筑。须弥基座雕式精美，基座外石廊上有龙、鹿和花草
浮雕，栩栩如生。塔之六层有二石匾(bian)，二层另有一“蛟腾凤起”
石匾，相传建塔本为镇妖。
LONG );
	set("exits", ([
		"southwest"    : __DIR__"yuandong",
	]));
	set("item_desc", ([
		"bian" : "
民       文
财       运
永       遐
阜       昌\n\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
