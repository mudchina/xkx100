// mudlist.c
inherit F_CLEAN_UP;

#include <ansi.h>
#include <net/daemons.h>
#include <net/macros.h>



#define	SYNTAX	"指令格式：mudlist [<Mud 名称>]\n"

int main(object me, string arg)
{
	mapping mud_list;
	mapping mud_svc;
	mixed *muds;
	string output;
	int loop, size;

	if( !find_object(DNS_MASTER) )
		return notify_fail("网路精灵并没有被载入，请先将网路精灵载入。\n");

	//	Obtain mapping containing mud data
	mud_list = (mapping)DNS_MASTER->query_muds();

	// so we recognise ourselves as a DNS mud
	mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

	if(!mud_list)
		return notify_fail( MUD_NAME + "目前并没有跟网路上其他 Mud 取得联系。\n");

	//	Get list of all mud names within name server
	muds = keys( mud_list ) - ({ "DEFAULT" });

	//	Place mudlist into alphabetical format
	muds = sort_array(muds, 1);

	// 	If mudname provided, search server's database for a match
	//	and display its cooresponding address
	if(arg && arg != "") {
		arg = htonn(arg);

		if(!mapp( mud_list[arg] )) {
			write(MUD_NAME + "并没有和这个 Mud 取得联系。\n");
			return 1;
		}
		printf("有关 %s 的资讯：\n%O\n", arg, mud_list[arg]);
		return 1;
	}

	output = "ＭＵＤ名称\t 中文名称\t  网   址\t端口\t玩家数\n───────────────────────────────\n";

	//	Loop through mud list and store one by one
	for(loop = 0, size = sizeof(muds); loop<size; loop++)
		output += sprintf("%-14s%-18s%6s\t%s\t%s\n", muds[loop], 
			mud_list[muds[loop]]["MUDNAME"],
			mud_list[muds[loop]]["HOSTADDRESS"],
			mud_list[muds[loop]]["PORT"],
			mud_list[muds[loop]]["USERS"] );
			this_player()->start_more( output );

	return 1;
}


int help(object me)
{
	write(@HELP
指令格式：mudlist [<泥巴名称>]

    这个指令让你列出目前跟这个 Mud 取得联系中的其他 Mud。
HELP
	);
	return 1;
}

