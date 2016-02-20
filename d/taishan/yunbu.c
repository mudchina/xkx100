// Room: /d/taishan/yunbu.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "云步桥");
	set("long", @LONG
在快活三里北首就是云步桥。因谷深林茂，常有云雾萦绕，杨承训
题“云步桥”。桥北大壑忽临断崖，壁立如削。崖上石坪坦豁，传宋真
宗曾在此驻跸，故名御帐坪，今柱窝尚存。岱顶下诸水奔流而来，飞瀑
下泻，溅沫迸珠，生云化雾，蔚为壮观，故又名飞瀑岩、天河、护驾泉。
崖上有“红桥飞瀑”、“霖雨苍生”、“河山元脉”、“太古清音”等
题刻。明代陈凤梧有诗：“百丈崖高锁云烟，半空垂下玉龙涎。天晴六
月常飞雨，风静三更自奏弦。苍水佩悬云片片，珠帘洞织月娟娟。晚山
倒着肩舆下，回看斜阳景更艳。”
    此处东有酌泉亭，由此西上，就是三蹬崖。
LONG );
	set("exits", ([
		"east"   : __DIR__"zhuoquan",
		"south"  : __DIR__"kuaihuosan",
		"westup" : __DIR__"sandengya",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 390);
	set("coor/y", 680);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
