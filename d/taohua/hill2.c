// Room: /d/taohua/hill2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

string look_bei();
int do_study(string arg);

void create()
{
	set("short", "山顶");
	set("long", @LONG
这里是山顶，很意外地，你发现东边有一座高台。一道石梁凌空而
架，连接着这里和那边的入口。几步之外立着一座石碑(shibei)。
LONG
	);
	set("exits", ([ 
		"southdown" : __DIR__"hill1",
		"east" : __DIR__"entrance",
	]) );
	set("item_desc", ([
		"shibei" : (: look_bei :),
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");
	set("coor/x", 8510);
	set("coor/y", -4680);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_study", "du");
	add_action("do_study", "study");
}

string look_bei()
{
	write("石碑上刻着：\n");
	write("    一日之四象：当午之时，日耀当空，光浴山河，阳气之极盛，是为太阳。\n");
	write("                当酉之时，日渐西山，群星显现，阳衰而阴盛，是为少阳。\n");
	write("                当子之时，玉兔东升，繁星闪动，阴气之极盛，是为太阴。\n");
	write("                当卯之时，旭日初现，群星无光，阳盛而阴衰，是为少阴。\n");
	write("    一月之阴阳：自初一而至十五，月形趋圆，渐阴之象，月圆则阴气最盛。\n");
	write("                十五之后，月形趋缺，渐阳之象，月缺则阴气最衰。\n");
	write("    一年之地支：正月阳气动，去黄泉欲上书，阴尚强也。引达于寅。\n");
	write("                二月万物冒地而出，像开门之形。冒茆于卯。\n");
	write("                三月阳气动，雷电振，民农时也，物皆生。振美于辰。\n");
	write("                四月阳气已出，阴气已茂，万物见，成文章。巳盛于巳。\n");
	write("                五月阴气牾逆阳，冒地面出也。咒布于午。\n");
	write("                六月滋味也，像木重枝叶也。味暖于未。\n");
	write("                七月阴气成体，自申东。申坚于申。\n");
	write("                八月黍成可以酹酒。留执于酉。\n");
	write("                九月阳气微，万物毕成，阳下入地也。毕入戌。\n");
	write("                十月微阳起接阴。该阂于亥。\n");
	write("                十一月阳气动，万物滋。孳萌于子。\n");
	write("                十二月万物动用事，像手五形。纽牙于丑。\n");
	write("    五行之三合：水申生，子旺，辰死。三支皆水。\n");
	write("                火寅生，午旺，戌死。三支皆火。\n");
	write("                木亥生，卯旺，未死。三支皆木。\n");
	write("                金巳生，酉旺，丑死。三支皆金。\n");
	write("                土午生，戌旺，寅死。三支皆土。\n");
	return "";
}

int do_study(string arg)
{
        object me = this_player();

	if (arg != "shibei" && arg != "bei")
		return 0;

	if (me->is_busy()) {
		write("你现在正忙着呢。\n");
		return 1;
	}

	if( me->is_fighting() ) {
		write("你无法在战斗中专心下来研究碑上的文字！\n");
		return 1;
	}

	if (me->query("jing") < 30) {
		write("你太累了，无法集中精神来研究碑上的文字。\n");
		return 1;
	}
	if (me->query_skill("qimen-wuxing", 1) > 150) {
		write("你仔细地读了一遍碑上的文字，发现已经太浅显了，无法学到新的知识。\n");
		return 1;
	}
	if (me->query_skill("qimen-wuxing", 1) < 50) {
		write("你仔细地读了一遍碑上的文字，感到无法完全理解。\n");
		return 1;
	}
	me->receive_damage("jing", 25);
	message_vision("$N仔细地注视着石碑上的文字。\n", me);
	write("你对于六壬奇门之学的精深之处有了进一步的认识。\n");
	me->improve_skill("qimen-wuxing", me->query("int") / 2 + random(me->query("int") / 2));
	return 1;
}