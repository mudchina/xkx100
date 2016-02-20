// Room: /d/jiaxing/mishi.c
// Last Modified by winder on Nov. 17 2000

#define PAINTINGS	20

inherit ROOM;

int do_move(string);
int do_open(string);
int do_browse(string arg);
string look_jiaceng();
string look_hole();

int *index = ({0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20});
string *paintings = ({
"赫然竟是画圣吴道子的“送子天王图”！",
"没想到却是唐代阎立本的“步辇图”。",
"张择端的“清明上河图”！你惊呆了。",
"却原来是唐代李思训的“江帆楼阁图”。",
"居然是王维的“伏生授经图”，王维以诗著称，工山水，却也有如许神妙的人物画。",
"上面题着“韩熙载夜宴图”，竟是五代南唐画家顾闳中的真迹。",
"乃是北宋李公麟的“五马图”。",
"乃是南宋梁楷的“太白行吟图”。",
"乃是一幅“匡庐图”，右上端题有“荆浩真迹神品”六字。",
"居然是五代关同的“山溪待渡图”。",
"却原来是五代李咸熙的“小寒林图”。",
"没想到却是南唐董源的“潇湘图”。",
"上面题着“秋山问道图”，呀，这不是宋初名僧巨然的大作吗？",
"北宋米友仁的“楚山清晓图”！你惊呆了。",
"原来是南宋马远的“寒江独钓图”。",
"赫然竟是顾恺之的“凫雁水鸟图”！",
"乃是唐代韩干的“照夜白”。",
"原来是北宋崔白的“寒雀图”。",
"却是唐末徐熙的“雏鸽药苗图”。",
"竟是宋徽宗亲笔所画的“雪江归棹图”！",
"怎么可能？竟然是据说失传已久的北宋范宽的真迹“溪山行旅图”！",
});

void create()
{
	int temp, i, j;

	set("short", "密室");
	set("long", @LONG
这是一间设计精巧的密室，并不很大，但是却不让人觉得拥挤。地
下有一具干枯的骸骨 (haigu)，旁边则是一口生锈了的大铁箱(xiang)。
墙上有一个小小的圆孔(kong)，通过它能看到外面的情况。
LONG
	);
	set("no_clean_up", 0);

	set("item_desc", ([
		"haigu" : "一具干枯的骸骨。\n",
		"xiang" : "一口沉重的大铁箱，锈迹斑斑，所幸的是箱盖还可以打开。\n",
		"jiaceng" : (: look_jiaceng :),
		"hole" : (: look_hole :),
		"kong" : (: look_hole :),
	]) );

	set("exits", ([
		"out": __DIR__"xiaodian",
	]) );

	set("coor/x", 1560);
	set("coor/y", -1061);
	set("coor/z", 0);
	setup();
	for (i = 0; i < PAINTINGS; i++)
	{
		j = random(PAINTINGS);
		while (j == i)
			j = random(PAINTINGS);
		temp = index[i];
		index[i] = index[j];
		index[j] = temp;
	}		
}

void init()
{
	add_action("do_move", ({"move", "yi"}));
	add_action("do_open", ({"open", "kai", "dakai"}));
	add_action("do_browse", ({"browse", "check", "examine", "fan", "cha", "liulan", "jiancha"}));
}

string look_jiaceng()
{
	if (this_player()->query_temp("thd_jiaceng")) 
		return "这是一个精巧的设计，不打开夹层你是看不到里面的东西的。\n";
	return "你要看什么？\n";
}

string look_hole()
{
	"/cmds/std/look.c"->main(this_player(),"out");
	return "";
}

void delete_tiepai()
{
	delete("tiepai_got");
}

void delete_shanshui()
{
	delete("shanshui_got");
}

void delete_xishan()
{
	delete("xishan_got");
}

int do_move(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("你正忙着呢！\n");
	if (arg == "haigu") {
		if (!query("tiepai_got") && !present("qulingfeng tiepai", me)
		&& !present("qulingfeng tiepai",this_object())) {
			write("你试着挪动尸体，发现原来在尸体下面还压着一枚铁牌。\n");
			set("tiepai_got",1);
			new(__DIR__"obj/tiepai")->move(this_object());
			remove_call_out("delete_tiepai");
			call_out("delete_tiepai", 300);
		}
		else {
			write("你试着挪动尸体，却什么也没有发现。\n");
		}
		return 1;
	}
	return notify_fail("你要搬动什么？\n");
}

int do_open(string arg)
{
	int thdx, thdy;
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("你正忙着呢！\n");
	if (arg == "xiang") {
		if (me->query_temp("thd_jiaceng")) {
			write("铁箱已经被你打开了！\n");
			return 1;
		}
		thdx = random(20) + 30;
		thdy = random(20) + 30;
		write("你用劲打开了箱子，发现里面竟藏有着无数的大内密宝。
而在珠宝的下面，有一张发黄的海图。\n");
		write("中间的一个地方用粗笔画了个圆圈，旁边用潦草的字迹写着(" + thdx + "," + thdy + ")的字样。\n");
		write("再仔细地观察这个箱子，似乎还藏有夹层(jiaceng)。\n");
		me->set("thd/x",thdx);
		me->set("thd/y",thdy);
		me->set_temp("thd_jiaceng", 1);
		return 1;
	}
	if (arg == "jiaceng") {
		if (me->query_temp("thd_jiaceng") == 1) {
			me->set_temp("thd_jiaceng", 2);
			me->set_temp("thd_shanshui", 10 + random(5));
			me->delete_temp("thd_painting");
			write("你轻轻地翻开夹层，发现里面竟然是一轴轴的画卷(painting)，\n都是名家所做的精品。\n");
			return 1;
		}
		else if (me->query_temp("thd_jiaceng")) {
			write("夹层已经被你打开了！\n");
			return 1;
		}
	}
	return notify_fail("你要打开什么？\n");
}

int do_browse(string arg)
{
	object me = this_player();
	int painting_no;

	if (me->query_temp("thd_jiaceng") < 2)
		return 0;

	if (arg != "hua" && arg != "painting")
		return notify_fail("你要翻查什么？\n");

	painting_no = me->query_temp("thd_painting");
	me->add_temp("thd_painting", 1);
	if (painting_no == me->query_temp("thd_shanshui") && !query("shanshui_got") && me->query_temp("find_shanshui") && !present("shanshui hua", me) && !present("shanshui hua", this_object()))
	{
		write( "你随手打开一轴画卷，是一幅泼墨山水，令你觉得很奇怪的是，此画风骨虽佳，但少了含蕴韵致，不象是名家手笔。\n");
		new(__DIR__"obj/shanshui")->move(this_object());
		set("shanshui_got",1);
		remove_call_out("delete_shanshui");
		call_out("delete_shanshui", 300);
		return 1;
	}
	if (painting_no > PAINTINGS)
		return notify_fail("你都看遍了，还赖在这里干嘛？！\n");
	write("你随手打开一轴画卷，" + paintings[index[painting_no]] + "\n");
	if (painting_no == PAINTINGS && !query("xishan_got") && !present("xi shan xing lv tu", me)
	&& !present("xi shan xing lv tu", this_object())) {
		new(__DIR__"obj/xishanxinglvtu.c")->move(me);
		set("xishan_got",1);
		remove_call_out("delete_xishan");
		call_out("delete_xishan", 500);
		return 1;
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	me->delete_temp("thd_jiaceng");
	me->delete_temp("thd_shanshui");
	me->delete_temp("thd_painting");
	return ::valid_leave(me, dir);
}