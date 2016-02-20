// Room: /d/yanping/zhouxue.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "州学");
	set("long", @LONG
延平府名优荟萃，文风昌盛。明代海瑞曾在此任过教谕。杨时、罗
从彦、李炯、朱熹四大名儒曾在此讲学，被后人称为“延平四贤”，延
平府亦被誉为“理学名邦”、“东南邹鲁”，城内五步一塾，十步一庠，
人才蔚起。宋咸淳元年（1265年）卅一人同第进士，为古今所罕见。布
衣黄裳为宋神宗元丰五年（l082）壬戌科状元。他就是奉旨编撰《万寿
道藏》，悟彻绝世武功，留下《九阴真经》的正主儿。现在他正在延平
书院做他的活儿呢。
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"meishanpo",
		"southdown" : __DIR__"xishan",
	]));
	set("objects", ([
		"/d/taishan/npc/shu-sheng": random(2)+1,
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	set("coor/x", 1450);
	set("coor/y", -6170);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
