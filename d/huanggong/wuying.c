// Room: /d/huanggong/wuying.c

inherit ROOM;

void create()
{
	set("short", "武英殿");
	set("long", @LONG
这是武英殿, 在这陈列的是各式各样的物饰仪器. 原来这里是皇帝
斋戒之处. 后来这里又是内务府属下的造办处, 并在此设立修书处, 拣
派翰林儒臣校刊书籍. 此处的新书遂称"殿版"书.
LONG
	);
	set("exits", ([
		"east"      : __DIR__"guangchang",
		"west"      : __DIR__"xihuamen",
		"south"     : __DIR__"nanxundian",
		"north"     : __DIR__"neiwufu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -220);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}