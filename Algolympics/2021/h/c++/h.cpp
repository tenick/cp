#include <unordered_set>
#include <array>
#include <cmath>
#include <cstdlib>

typedef long long int ll;

namespace std
{
    template<typename T, size_t N>
    struct hash<array<T, N> >
    {
        typedef array<T, N> argument_type;
        typedef size_t result_type;

        result_type operator()(const argument_type& a) const
        {
            hash<T> hasher;
            result_type h = 0;
            for (result_type i = 0; i < N; ++i)
            {
                h = h * 31 + hasher(a[i]);
            }
            return h;
        }
    };
}

void displayArr(std::array<ll, 3> arr){
    printf("{ ");
    int count = 0;
    for (ll i : arr){
        count++;
        if (count != arr.size())
            printf("%lld, ", i);
        else
            printf("%lld ", i);
    }
    printf("}");
}

void displayUSet(std::unordered_set<std::array<ll, 3>> uset){
    printf("{");
    for (std::array<ll, 3> arr : uset){
        printf("{ ");
        int count = 0;
        for (ll i : arr){
            count++;
            if (count != arr.size())
                printf("%lld, ", i);
            else
                printf("%lld ", i);
        }
        printf("}");
    }
    printf("}");
}

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

ll multiGCD(std::array<ll, 3> arr){ 
    ll result = 0; 
    for (ll element: arr){ 
        result = gcd(result, element); 

        if(result == 1)
           return 1;
    } 
    return result; 
}

int main(){
    ll s, t;
    scanf("%lld%lld", &s, &t);
    ll stars[s][3];
	ll b[s];
    ll telescopes[t];
    
    // get stars
    for(ll i = 0; i < s; i++){
        for(int j = 0; j < 3; j++){
            scanf("%lld", &stars[i][j]);
        }
		scanf("%lld", &b[i]);
    }
    
    // get telescopes
    for(ll i = 0; i < t; i++){
        scanf("%lld", &telescopes[i]);
    }
    
    // output all stars telescope can see
    for(const ll &telescope : telescopes){
		ll stars_saw = 0;
        std::unordered_set<std::array<ll, 3>> star_vectors;
        
        for (ll i = 0; i < s; i++){
			ll a = b[i] / (std::pow(stars[i][0], 2) + std::pow(stars[i][1], 2) + std::pow(stars[i][2], 2));
			//printf("Star: [%lld, %lld, %lld, %lld] ", stars[i][0], stars[i][1], stars[i][2], b[i]);
			//printf("a: %lld telescope sensitivity: %lld\n", a, telescope);
            // check if star can be seen
            // 1. if star's gabisibility >= telescope sensitivity, visible
            if (a >= telescope){
                // 2. check if there is some star between it
				ll vector_divisor = multiGCD(std::array<ll, 3>{std::abs(stars[i][0]),
																std::abs(stars[i][1]),
																std::abs(stars[i][2])});
                std::array<ll, 3> vector_direction = {stars[i][0] / vector_divisor,
														stars[i][1] / vector_divisor,
														stars[i][2] / vector_divisor};
				//printf("Direction: "); 
				//displayArr(vector_direction);
				//printf(" Divisor: %lld\n", vector_divisor);
                std::unordered_set<std::array<ll, 3>>::const_iterator found = star_vectors.find(vector_direction);
                if (found != star_vectors.end()){
					//printf("Seen stars:\n");
					//displayUSet(star_vectors);
                    continue;
				}
                else{
                    star_vectors.insert(vector_direction);
                    stars_saw++;
                } 
            }
        }
        printf("%d\n", stars_saw);
    }
    return 0;
}
