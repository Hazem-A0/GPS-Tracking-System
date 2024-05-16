# %%

import folium

# Read locations from text file
locations = [
    [30.0638748, 31.2800570],
    [30.0640544, 31.2799712],
    [30.0641943, 31.2798950],
    [30.0642706, 31.2798015],
    [30.0642166, 31.2796577],
    [30.0641853, 31.2795675],
    [30.0641522,31.2794726],
    [30.0641322,31.2794109],
    [30.0640927,31.2793036],
    [30.0640733, 31.2792262],
]


m = folium.Map(location=locations[0], zoom_start=19)
for loc in locations:
    folium.Marker(location=loc).add_to(m)

# display
m

# %%
