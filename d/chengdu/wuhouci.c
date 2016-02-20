// Room : /d/chengdu/wuhouci.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
        set("short", "武侯祠");
        set("long", @LONG

          丞相祠堂何处寻？锦官城外柏森森。
          映阶碧草自春色，隔叶黄鹂空好音。
          三顾频烦天下计，两朝开济老臣心。
          出师未捷身先死，长使英雄泪满襟。

    这里就是被川人敬仰的武侯祠。这里安葬着三国时代的一代贤臣诸
葛亮，常有成都本地人和游客前来参拜。四周参天大树环绕着巨大陵墓，
大树上不时传来几声画眉鸟清脆的叫声。你念着“出师未捷身先死”，
心中不由得一阵黯然。西面有座陵墓。
LONG	);
        set("exits", ([
		"west"      : __DIR__"lingmu",
		"northup"   : __DIR__"liubeidian",
		"southeast" : __DIR__"wuhoucigate",
	]));
        set("outdoors", "chengdu");
        set("coor/x", -8070);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

