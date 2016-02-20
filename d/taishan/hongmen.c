// Room: /d/taishan/hongmen.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "红门宫");
	set("long", @LONG
红门宫东临中溪，西靠大藏岭，是泰山中溪的门户，呈半封闭凹形
空间。再加宫前三重白色石坊及碑碣，构成一组高低错落、色彩鲜明、
形若天梯的古建筑群。自飞云阁洞北望，林荫夹道，石级绵延。自古有
“红门晓日”之景。清人赵国麟留诗：“凌晨登红门，霁色明朝旭。俯
视万家烟，平畴尽新绿。”
LONG );
	set("exits", ([
		"east"      : __DIR__"mileyuan",
		"northeast" : __DIR__"xiaodongtian",
		"northup"   : __DIR__"yitian",
		"southdown" : __DIR__"baihe",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", 550);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
