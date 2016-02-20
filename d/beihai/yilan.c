// /d/beihai/yilan.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "漪澜堂");
	set("long", @LONG
涟漪堂与北岸五龙亭隔水相望，其上层两侧之廊折下，形成一独特
形式之建筑。北坡石岩陡削，石洞、亭阁错迭，洞室相通，极尽机巧，
有酣古堂、写妙石室、盘岚精舍、环碧楼、一壶天地亭、小昆邱亭等。
延楼回廊外绕汉白玉护栏，东南为倚晴楼，西南为分凉阁，分别作为漪
澜堂的入口。登此楼可南瞻白塔，北瞰碧波。有金山江天一览之胜。
LONG
	);
	set("exits", ([
		"southup"   : __DIR__"baita",
		"northeast" : __DIR__"dukou2",
		"southwest" : __DIR__"yuegu",
		"southeast" : __DIR__"shiqiao",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 4100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
