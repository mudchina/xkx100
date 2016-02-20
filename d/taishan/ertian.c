// Room: /d/taishan/ertian.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "二天门");
	set("long", @LONG
这里又叫「中天门」。中天门峻岭阔谷，楼阁簇拥。东有中溪山突
兀俏丽，可观日出，望晚霞；西有凤凰岭蜿蜓伸展，可远眺傲徕雄姿，
俯视山下城廓。伫立坊下，北瞻巍巍岱峰，众山拱立，林茂泉飞，缆车
凌空，天然成画。
    一般的登山者来到这里都已累极，但是这里才是泰山的一半啊！面
对前面险峻的十八盘，很多人都不禁犹豫起来。
LONG );
	set("exits", ([
		"north"     : __DIR__"kuaihuosan",
		"southdown" : __DIR__"huima",
	]));
	set("objects",([
		__DIR__"npc/tiao-fu" : 1,
		CLASS_D("taishan")+"/tiansong" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 390);
	set("coor/y", 660);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
